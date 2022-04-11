# gauss-jordan
c++ program to manipulate matrices

## Set up
download main.cpp and run
```g++ main.cpp -o gauss```
make sure you have g++ latest version installed

## How to use
Once you run the program, you'll have to enter the matrix dimensions and then its rows <br>
![image](https://user-images.githubusercontent.com/68504851/162779009-457479ea-51cd-4c38-b0b4-a746de6886a4.png) <br>
Notice you can either enter integers or fractions (not decimal numbers!!)
The next step is to manipulate the matrix as you'd like. <br>
The accepted commands are:
- ```s {l} {k}``` - swaps rows l and k
- ```m {l} {x}``` - multiplies row l by x
- ```d {l} {x}``` - divides row l by x
- ```a {l} {x} {k}``` - adds x*k to row l
> After each command, the new matrix will be printed

Example: <br>
![image](https://user-images.githubusercontent.com/68504851/162780090-046493e0-807d-4556-ab1b-1bbb3f68dda5.png)

