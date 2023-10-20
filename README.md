# Car-Racing-game-with-C
- Car racing game that I prepared using C programming language and gotoxy
  The gameplay of the game is explained within the game. To have more fun, you can take turns playing with your friends and race against the score if you continue without closing the application. Also, don't forget to try the difficulty options.
### HAVE LOTS OF FUN...

- I have mentioned the codes of the game below.

<img src="https://github.com/MertErenKekuc/Car-Racing-game-with-C/assets/92688288/08ae6fb3-bb0a-4224-a56d-1d63f79071e7)https://github.com/MertErenKekuc/Car-Racing-game-with-C/assets/92688288/08ae6fb3-bb0a-4224-a56d-1d63f79071e7" alt="alt text" width="480" height="270">
<img src="https://github.com/MertErenKekuc/Car-Racing-game-with-C/assets/92688288/eeb214a0-e806-47c6-8d8f-0ccaaddc0c70" alt="alt text" width="480" height="270">

<p></p>

- The game is console-based and written in C programming language. The code gives the user the option to play games at different difficulty levels. I have explained the functions and main steps below:

- The gotoxy(int x, int y) function moves the cursor to the specified location on the console screen. To do this, it uses the SetConsoleCursorPosition function of the windows.h library.

- The setcursor(int visible) function sets the visibility of the cursor on the console screen. This is achieved by using the CONSOLE_CURSOR_INFO and SetConsoleCursorInfo functions of the windows.h library.

- The drawBorder() function creates a border around the playing field. This is drawn using the ± character using two for loops.
 <p></p>

<img src="https://github.com/MertErenKekuc/Car-Racing-game-with-C/assets/92688288/c617cb1b-ce2c-47f3-8f75-dde054c9d39d" alt="alt text" width="480" height="270">
<img src="https://github.com/MertErenKekuc/Car-Racing-game-with-C/assets/92688288/99a64537-8869-44c9-94b5-573b6464cc1d" alt="alt text" width="480" height="270">

<p></p>

- The genEnemy(int ind) function randomly generates the location of a given enemy. This assigns a random value within a specified range using the rand() function.

- The drawEnemy(int ind) function draws a specific enemy to the screen. This uses the printf() function to draw a pattern representing the enemy using the characters **** and **.

- The eraseEnemy(int ind) function deletes a specific enemy from the screen. This uses the printf() function to use space characters at the enemy's location.

- The resetEnemy(int ind) function resets the position of a specific enemy. This is accomplished using the eraseEnemy() and genEnemy() functions.

- The drawCar() function draws the user's car on the screen. This uses the car array using the printf() function.

- The eraseCar() function deletes the user's car from the screen. This uses space characters at the position representing the car using the printf() function.


 <p align="center">
  <img src="https://github.com/MertErenKekuc/Car-Racing-game-with-C/assets/92688288/91e0e8e5-6036-4952-a4d9-f1473543cafa" alt="alt text" width="480" height="270">
</p>

<p></p>

- The collision(int ind) function checks if there is a collision between the car and the enemy. This is accomplished by controlling the distance between the car and the enemy and their location.

- The gameover() function notifies the user when the game has ended. This displays a message on the screen and prompts the user to press a key.





