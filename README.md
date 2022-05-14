# polynomial  calculation

======Description======

In our program we will perform a polynomial calculation using two different programming methods, we will get the polynomial and the value that the user will want to place in the polynomial, an explanation for the methods:

For Part A:
We get a polynomial and a value that we want to place in the polynomial, we do it as follows:
We get the string and divide it into 2 parts, the polynomial itself and the value alone, we can know to divide by finding the comma, then we produce the threads according to the amount of variables we have in the polynomial and after the division we made in the polynomial we send the polynomial (divided) to the function of The processes there are basically. Will perform the calculation and kill the thread itself after its completion and we will keep all the results in a data structure so that we can perform the calculation in main and print it (we will save the free organ immediately after the absorption of the polynomial).

For Part B:
We create a shared memory that will help us for all the processes we will create according to the amount of variables and the processes could use memory thanks to a key we will create for memory
And only after that
We get a polynomial and a value that we want to place in the polynomial, we do it as follows:
We get the string and divide it into 2 parts, the polynomial itself and the value alone, we can know to divide by finding the comma, then we produce the processes according to the amount of variables we have in the polynomial and after the division we made in the polynomial we send the polynomial (divided) to calculation functions Ours and then we will keep the values ​​in our shared memory. Finally, we will release the resources we used:
Our shared memory.


Attention!

We will perform the actions of the program until you type "done" for us
Once you type this we will immediately stop the program.


Difference between the methods of Part A and Part B:

1-Waiting to complete processes
For Part A we use threads so that the processes work in parallel
For Part B we work with processes so that any process that executes commands we will have to wait for to complete.
2-Memory sharing:
For part B we use the functions of sharing information with shared memory so that we can perform calculations at the end.
For Part A we use threads so we will not have to perform memory sharing because we work in parallel so we get the information at the same time.
3-Speed ​​of calculations
For Part A the calculation will be faster following the differences noted before.
For part B the calculation will be a bit slower because each time we will have to wait for the calculation to perform a process.

The code change:
1-Added or removed from #include.
2-The big change was in main because basically there we created the processes or threads and also for part in we had to add the shared memory.
3- Deleting the function for the treads for part a.
