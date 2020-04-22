/*This program will tell print out a table of Fibonacci numbers. It also calculates and prints the time to do the calculation recursivly vs. how long it takes to calculate iteratively.
I've had difficulty running it correctly in Codeblocks.
In codeblocks the numbers don't print correctly past n=47. If you run the program in something else, for example, cygwin console,
then you get more numbers. The program can only run up to n=92 for signed 64-bit integers.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


//iterative function
long long fib_series_iterative(int n)
{
    long result=0; //current result
    long result_1=1; //result one sdtep ago
    long result_2=0; //result two steps ago

    for(int i=0; i<n; i++)
    {
        result_2=result_1;
        result_1=result;
        result=result_1+result_2; //set the current result
    }
    return result;
}

//recursive function
long long fib_series_recursive(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fib_series_recursive(n-2)+fib_series_iterative(n-1);
    }
}

int main()
{
    int n;
    int i;
    printf("Enter n:");
    scanf("%d",&n);
    printf("n\tF(n)\tTime Taken to Execute Recursively (s)\tTime taken to Execute Iteratively\n");
    for(i=0; i<=n; i++)
    {
        struct timeval start, end;

        gettimeofday(&start, NULL);
        long long recursive_result=fib_series_recursive(i);
        gettimeofday(&end, NULL);

        double time_taken_recursion = end.tv_sec + end.tv_usec / 1e6 -
        start.tv_sec - start.tv_usec / 1e6;

        gettimeofday(&start, NULL);
        long long iterative_result=fib_series_iterative(i);
        gettimeofday(&end, NULL);

        double time_taken_iteration = end.tv_sec + end.tv_usec / 1e6 -
        start.tv_sec - start.tv_usec / 1e6;
        printf("%d\t %lli \t %lf \t %lf \n",i,recursive_result,time_taken_recursion, time_taken_iteration);
    }

    return 0;
}
