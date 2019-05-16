#ifndef _INC_BASE_H_
#define _INC_BASE_H_

/*
This is not strictly needed.
The GCC will normally choose to inline our simple functions anyway.
A simple `inline` will prevent the compilier from generating
full versions of the function (as well as inlining).
The "always_inline" should cause a warning to be raised if a function
is ever not inlined.
*/
#define ONLYINLINE __attribute__((always_inline)) inline

#endif//_INC_BASE_H_
