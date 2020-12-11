# **Lab 2: FreeRTOS functions on ESP8266**
<br>
FreeRTOS specifies that port-specific files must be defined for the target platform, and that an application-specific configuration file should be included in each new project. For any project that you have already created, identify the following files and how changes in any one will affect the FreeRTOS configuration:
- /project/sdkconfig
- /project/build/include/sdkconfig.h
- /sdk/components/freertos/port/esp8266/include/freertos/FreeRTOSConfig.h <br>
For each exercise, ensure that the output file, the appropriately commented source files, and the final binary files, are part of your github repository.<br><br>

<ol>
    <li>
        Create an example application with three tasks that are created in app_main. Two tasks should share a single GPIO pin (you may use the pin connected to the built-in LED for convenience). One task will turn the GPIO pin on, actively wait for 0.5 seconds, and task-delay for 1 second. The other will turn the GPIO pin off, actively wait for 0.5 seconds, and task-delay for 1 second. The GPIO pin should be managed using a semaphore/mutex. The third task will print a status message only, and task-delay for 1 second. Each task should have it's own priority level. Build and run your code.
    </li>
    <li>
        Adjust the example from 1) in the following ways: a) set the example to round-robin scheduling where tasks have the same priority b) utilise Priority Inheritance to manage the mutex. Vary the assigned priorities for your tasks, and look at the difference in performance. Is it what you expected?
    </li>
    <li>
        Use the IDLE "hook" function to put the processor to sleep for some time when the system is not going to be "in-use". Does the use of the processor sleep affect the system performance?
    </li>
</ol>