# Bamtang_Games_GameDev_Q_4_POKER_FACE
Small demo (written in C++) that implements the logic of a poker game, (particularly its variant 'Texas Poker'), between two players, using text files as Input and as Output. - My Answer to the Bamtang Games' [Game Programmer Exam (originally published in 2018)](README_QuestionDetails/BAMTANG_ExamCpp_2018.pdf):

## Question number 4.
## 4. POKER FACE

[Spanish original Question:]

En esta versión simplificada del juego de Poker, existen 4 tipos de cartas (abreviaciones entre paréntesis):

##### Tréboles (C), Espadas (S), Corazones (H) y Diamantes (D).

Hay 13 cartas por cada tipo, dando un total de 52 cartas, las cartas ordenadas de menor valor a mayor valor son:

##### 2, 3, 4, 5, 6, 7, 8, 9, 10 (T), Jack (J), Reina (Q), Rey (K), Ace (A).

Una mano consiste de 5 cartas. Existen 10 clases de manos, ordenadas de menor a mayor son:

	1-	HIGH CARD: El valor de la carta de mayor valor.
	2-	ONE PAIR: Dos cartas del mismo valor (un par).
	3-	TWO PAIRS: Dos pares diferentes.
	4-	THREE OF A KIND: Tres cartas del mismo valor.
	5-	STRAIGHT: Todas las cartas son valores consecutivos.
	6-	FLUSH: Todas las cartas son del mismo tipo.
	7-	FULL HOUSE: Tres cartas del mismo valor y un par.
	8-	FOUR OF A KIND: Cuatro cartas del mismo valor.
	9-	STRAIGHT FLUSH: Todas las cartas son valores consecutivos del mismo tipo.
	10-	ROYAL FLUSH: 10, Jack, Queen, King, Ace, del mismo tipo.


<p align="center">
   
   <img src="ReadmeImgs/poker-hand-rankings.png?raw=true">
   
   <font size="1">
      <p align="center">
         <figcaption">
            <p align="center">Poker Hand Hierarchy</p>
            <p align="center">Source: https://www.cardschat.com/poker-hands/</p>
         </figcaption>
      </p>
   </font>
</p>


Si dos jugadores tienen manos de la misma clase entonces la mano que esta conformada por cartas de mayor valor gana;
por ejemplo un par de ochos le gana a un par de cincos (ver ejemplo 1 más abajo).

Si aun así hay empate, por ejemplo, ambos jugadores tiene un par de reinas, entonces las cartas de mayor valor de cada mano
son comparadas (ver ejemplo 4 de abajo);
si las cartas de mayor valor son iguales, las cartas que le siguen de mayor valor son comparadas, y así sucesivamente.

Ejemplos:

<pre>
Mano        Jugador 1       Jugador 2           Ganador

1       5H 5C 6S 7S KD      2C 3S 8S 8D TD      Jugador 2
        Par de cincos       Par de ochos
2       5D 8C 9S JS AC      2C 5C 7D 8S QH      Jugador 1
        HIGH CARD Ace       HIGH CARD Queen
3       2D 9C AS AH AC      3D 6D 7D TD QD      Jugador 2
        Tres Aces           FLUSH de diamantes
4       4D 6S 9H QH QC      3D 6D 7H QD QS      Jugador 1
        Par de reinas       Par de reinas
        Máxima carta 9      Máxima carta 7
5       2H 2D 4C 4D 4S      3C 3D 3S 9S 9D      Jugador 1
        Full House de 4     Full House de 3
</pre>


Verifica tu código con el archivo de jugadas: poker.txt, el cual contiene 1000 manos aleatorias
entregadas a dos jugadores. Cada línea del archivo contiene 10 cartas (separadas por un solo espacio):
 las primeras cinco son las cartas del jugador 1 y el resto son las del jugador 2.
De las 1000 manos en este archivo, el jugador 1 gana 376 manos.

##### Crea todas las funciones necesarias para resolver este problema de una modo genérico (por ejemplo: con otro archivo de jugadas).
##### Asume que todas las manos son válidas, sin caracteres inválidos ni cartas repetidas, que las manos no están ordenadas y que por cada línea existe un claro vencedor.

*******************************************************************************
(6 PUNTOS)
*******************************************************************************

#### Developer Notes:

#### 1- This source code was written in <strong> Visual Studio Community 2017 </strong> (IDE for C++), to build an executable file. 
#### It was configured to build the executable with ISO C++14 Language Standard (/std:c++14) options.

<p align="center">

   <img src="ReadmeImgs/1_e_ISO_LANGUAGE_STANDARD_CPP14_.png?raw=true">

   <font size="2">
      <p align="center">
         <figcaption"> ISO C++14 Language Standard (/std:c++14) option
         </figcaption>
      </p>
   </font>
</p>

#### 2- This game is about the 'Texas Poker' variant.

#### 3- The INPUT and OUTPUT Text Files (.txt) will be read and written in the same location (path) where the (.exe) executable file is located. 

#### 4- The INPUT text file used is a global variable, which is called in the code: '_INPUT_FILE_SHORT_NAME'; and the name of the Text File itself is: "poker.txt".

#### 5- The OUTPUT text file used is a global variable, which is called in the code: '_OUTPUT_FILE_SHORT_NAME'; and the name of the Text File itself is: "pokerOutput.txt".

*******************************************************************************

#### General Notes:

#### 1- [Game Programmer Exam Questions (originally published in 2018)](README_QuestionDetails/BAMTANG_ExamCpp_2018.pdf).

#### 2- [Bamtang Games' current Game Programmer Exam, as reference](https://www.bamtang.com/careers/game-programmer).

*******************************************************************************
Source Code By:	 Alejandro E. Almarza Martín
*******************************************************************************

MIT License

Copyright (c) 2020 AlMartson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
