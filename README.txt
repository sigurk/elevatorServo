CONTENTS OF THIS FILE
--------------------

 * Startup 
 * LED
 * Queue system
 * Inside elevator buttons
 * Outside elevator buttons

Startup
-------

 1. Turn the power button on the All In One Servolab on, to enable motor functioning.

 2. Check that these packages are installed on your arduino IDE:
   liquidcrystal.h 
   dac.h 
   Deque.h
   util/atomic.h

 3. Run script.


LED
---

Since the elevator is simulated and not physical, LEDs are utilized. 
LED lights up when elevator is at corresponding floor.

LED1 = floor1 '
LED2 = floor2 
LED3 = floor3 

QUEUE
-----

When a button is pressed while the script is already executing an action, this action is stored and
will be executed after the current action is finished. 


INSIDE ELEVATOR BUTTONS
-----------------------

Buttons 1-3 on the all in one servolab corresponds to the floorbuttons inside an elevator, 

Button 1 = Move elevator to floor 1
Button 2 = Move elevator to floor 2
Button 3 = Move elevator to floor 3
 
When one of these are pressed, the elevator moves to desired floor, which is indicated by the LEDs.

There is also a button which opens or closes the elevator doors, one push of button either opens or closes the doors
depending on the doorstate before button is pushed. 

Button 8 = Open/close door. 

If the doors are open and a button either inside or outside is pressed, the doors are closed automatically 
before the elevator starts moving.

OUTSIDE ELEVATOR BUTTONS
------------------------

Buttons 4-7 corresponds to the buttons outside the elevator. Possibility of calling elevator to floor 3 and 1, and on
floor 2 the direction you are intending to take the elevator is also included.

Button4 = Call to floor2, direction down
Button5 = Call to floor2, direction up
Button6 = Call to floor1
Button7 = Call to floor3

