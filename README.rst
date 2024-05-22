.. _debugging_faults:

Debugging faults
****************

Overview
********

A simple sample that can be used with any nrf board and
prints "Hello Faulting in ... 5 4 3 2 1", followed by a fault output to the console.

The purpose of this project is to show how to use tools like addr2line,
as well as entering debug mode to watch the CPU register content upon fault.

Exercises
*********

Debugging the fault:

- With logging enabled
- With logging in secure enabled
- Without logging enabled, by entering debug mode and reading the CPU register content upon fault

Use of debug tools, such as addr2line and .map file parsing, find the following:

- file:line_number
- The thread function/name that caused the fault by parsing the .map file

Understanding the boot process:

- Single-stepping through the boot process to see what is invoked before entering your program
- Understanding _INIT_PRIORITY of a subsys/driver, which is executed first? Let us look at the GPIO and SERIAL subsys


Reading material
****************

Init procedure in Zephyr:

`https://docs.zephyrproject.org/3.6.0/kernel/drivers/index.html#initialization-levels`

`https://academy.nordicsemi.com/courses/nrf-connect-sdk-intermediate/lessons/lesson-7-device-driver-model/topic/driver-implementation/`

addr2line usage in NCS:

`https://academy.nordicsemi.com/courses/nrf-connect-sdk-intermediate/lessons/lesson-2-debugging/topic/build-errors-and-fatal-errors/``


Building and Running
********************

This project is board agnostic, but it is recommended to use nRF5340-DK.
Running on a non-secure application allows to show secure faults.

Sample Output
=============

.. code-block:: console

    *** Booting nRF Connect SDK v3.5.99-ncs1-1 ***
    Hello Faulting project! Running on board $BOARD

    Will fault in ...  5 4 3 2 1 0
    [00:00:05.258,209] <err> os: ***** SECURE FAULT *****
    [00:00:05.258,209] <err> os:   Address: 0x0
    [00:00:05.258,239] <err> os:   Attribution unit violation
    [00:00:05.258,239] <err> os: r0/a1:  0x00000001  r1/a2:  0x2000cca0  r2/a3:  0x2000cca0
    [00:00:05.258,270] <err> os: r3/a4:  0x00000000 r12/ip:  0x00000000 r14/lr:  0x00008441
    [00:00:05.258,270] <err> os:  xpsr:  0x61000000
    [00:00:05.258,300] <err> os: Faulting instruction address (r15/pc): 0x00008442
    [00:00:05.258,331] <err> os: >>> ZEPHYR FATAL ERROR 41: Unknown error on CPU 0
    [00:00:05.258,361] <err> os: Current thread: 0x2000cca0 (unknown)



