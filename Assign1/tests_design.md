# Tests Design

The following suite of tests checks all methods defined for deques. For every deque method, a void function of the name `test_<method>` is defined in `Dtest.cpp`. For most methods, the corresponding test method prints out the expected result(final values in the deque or sometimes properties like size and capacity) of the function, then runs the deque method and displays the actual result. For some methods, like the `[]` accessors, the test program automatically checks if the actual behaviour is that expected and prints `passed` or `failed`. `Darraytest.cpp` defines the test function for the deque `[]` access operator.
### Cases
In each test function, cases are tested that...
- require methods to perform wraparound operations on the circular array,
	- *e.g.* enqueuing when the back has already reached the end of the underlying array)
- are "illegal"
	- *e.g.* accessing `DQ[9]` of a size 6 deque *DQ*
