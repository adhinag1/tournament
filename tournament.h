#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include<stdio.h>

typedef struct Player
{
	int offensive;
	int defensive;
	int number;
	int team;
	char *first;
	char *last;
} Player;

typedef struct Team 
{
	char * name;
	Player *players;
	int flag;
} Team;

#include"tournament.c"

Player * draftPlayers(char *filename, int team, int num_players);
Team * initializeTeam(char *Name,Player *players);
Team * game(Team * team1,Team * team2);
Team * tournament(Team **league,int num_teams);
void deleteTeam(Team *t);

#endif
