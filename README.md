# Homemade_Hash
Custom Hash created by me for uni project
### 128bit

## [v0.2](https://github.com/Definitelynotaspruce/Homemade_Hash/releases/tag/v0.2)
## [v0.1](https://github.com/Definitelynotaspruce/Homemade_Hash/releases/tag/v0.1)
It's working but it has a loooot of bugs....

## How to run the program

On a Windows machine
```
g++ main.cpp functions.cpp hash.cpp 
./a.exe
```
On a linux machine
```
g++ -o main main.cpp functions.cpp hash.cpp
<<<<<<< HEAD
./hash

```
If you want to test the hash type *test.cpp* instead of *main.cpp*

# Pseudo-code

```
Input - string line
Result - 128 bits

numberA = random prime intiger
numberB = random prime intiger
numberC = 0
    for j = 0; j < 4
        for i = 0; i < inputSize
            numberB = numberB * inputSize + NumberFromInputElementAtPosition_i
            numberA = numberA * NumberFromInputElementAtPosition_i + inputSize
            numberC = numberA*numberB; 
    hash[j] = bitsFrom(numberC)
    
return hash[0], hash[2], hash[1],hash[3]
```
My hash takes some random prime numbers as a base and then performs some calculations. The first loop is running 4 times (because each hash chunk is 32bit long and in total i get 128bits). The second loop runs *input.size()* times (if the string input is 45 char long it will loop 45 times). Then some calculations with prime numbers, ASCII numbers and inputSize are made and I crete 32bit chunk from the final number I got. This process repeats 4 times, then the chunks are concated and returned. Later I convert those bits into hex numbers.

# Hash analysis 

## Speed test
Speed of this hash was tested with konstitucija.txt file. 
Each line of this text file was hashed in average of 0.027715 seconds.

## Collision test
Collision tests were performed using randomly generated string lines with one char difference. (tmainly with 2500 pairs of lines with one different simbol). No collisions were found.

## Simbol by simbol difference 

| Input string | output hex                   | 
| ------------------ | ------------------------------------------------------------ |
| lietuva            |  dbb182fe87ef162622338da9812f0ec1|
| Lietuva            |  ced9329e74b574c6add8bae9bd889101|
| Lietuva!           | 6fac6f362fc91f56c6cceb56d41d9f56 |

Result of comparing each bit or hex simbol of the hash (2500 pairs of string lines with 10, 100 and 1000 chars)
 | | 10 | 100 | 1000
---------|----------|---------|--
 |hex | 89.9% | 85.4%|80.2%
 |binary | 70% | 68.4%|65.3%

## Results:

UPDATE: HASH IS WORKING
The hash is far from usable.
I couldn't determine the reason why it ignored simbol changes in the middle of input string.

