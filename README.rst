nanoCDR TODO
============

This is a proof of concept for communicating a Pixracer Autopilot and a Raspberry Pi connected through serial ports and using CDR serialization.

.. image:: doc/schema.png

Pixracer firmware
-----------------

In the Pixracer side, it will be used an application running an uORB node. This node will be subscribed to the IMU sensor data via the *sensor_combined* topic. The applications read the message in a loop, serializes the struct and writes it trough an UART port selected by the user.

To compile this appication along the PX4 firmware it is needed to add the *eprosima_cdr* folder on the examples folder (located on `src/examples<https://github.com/PX4/Firmware/tree/master/src/examples>`_). Then, the application must be registered in NuttShell adding a new line in `nuttx_px4fmu-v4_default.cmake<https://github.com/PX4/Firmware/blob/master/cmake/configs/nuttx_px4fmu-v4_default.cmake>`_ as described in the PX4 `documentation <https://dev.px4.io/tutorial-hello-sky.html#step-3-register-the-application-in-nuttshell-and-build-it>`_:

.. code-block:: shell

    # eProsima app
    examples/eprosima_cdr

Now, the application can be launched on NuttShell typing its name and passing an available serial port as argument. Using */dev/ttyACM0*
will use the USB port as output. Using */dev/ttyS1* or */dev/ttyS2* will write the output trough TELEM1 or TELEM2 ports respectively.

.. code-block:: shell

    > eprosima_cdr /dev/ttyACM0  #or /dev/ttySn

NOTE: If the UART port selected is busy, it's possible that Mavlink applications were using them. If it is the case, you can stop Mavlink from NuttShell typing:

.. code-block:: shell

    > mavlink stop-all

Raspberry PI application
------------------------

TODO

Result
------

If all steps has been followed, you should see this output on the Raspberry PI terminal.

TODO
