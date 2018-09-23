This code is an example of running independent style commands on an Arduino based robot.

You can create parallel and serial style commands and add them in any order.
When a command is activated its parallel (sibling) commands are also activated.
When a command terminates its sequential (child) command is then activated.

Each command extends the RobotCmd class, and provides three methods:
void initialise() - called once, when first activated
bool execute() - called multiple times - returns true if execution has completed, returns false if it should be called on the next loop.
void end() - called once after execute() returns true.

A command can do anything, but should NOT contain delay loops. If there are time based things, use the millis() function and check to see if the time to do your thing has passed.
