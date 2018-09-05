# Custom Game Tournament
Implemented tournament program with teams consisting of players. Players has following attributes,

Player struct that has the following attributes:
■	offensive (int)
■	defensive (int)
■	number (int)
■	team (int)
■	first (char *)
■	last (char *)

There are list of players in the .dat file from where the players are drafted into the teams, which has a structure
■	team_name
■	pointer to store players array

Game function takes two teams and applies the following logic to determine the winner. The Game logic is determined by,

■	The algorithm for determining the winner of a game is as follows:
    ●	Each team gets 10 attempts to score.
    ●	You must compare the defensive team’s players total defense with a random value between 0 and the offensive team’s total offense.
    ●	If the final offensive value is greater than the defense, the team has a scored.
■	Return a pointer to the winner.

Now Tournament function takes pointers to Team structs, and the number of teams as arguments to determine the winner. Number of Teams should be in the powers of 2. In Each round of tournament we use game function to determine the winner.

# Commands to run the program
Assuming you are in the directory where makefile is:

## To compile:
make all

## To run:
make run

## To clean:
make clean

## To check for memory leak
make checkmem
