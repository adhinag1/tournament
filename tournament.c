#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Player * draftPlayers(char *filename, int team, int num_players) {
	Player * playersArray = malloc(num_players * sizeof(Player));
	FILE *file;
	char buf[50];
	char *token;
	char *tokenArr[6];
	int playercount=-1;
	file = fopen(filename,"r");
	if(file == NULL) {
		printf("cannot open file");
	}
	else {
		while(fgets(buf, 50, file)!=NULL) {
			token = strtok(buf,",");
			int teamno= atoi(token);
			if(teamno == team) {
				playercount++;	
				int i=0;
				while(token != NULL) {
					tokenArr[i]=token;
					token = strtok(NULL,",");
					i++;
				}
				playersArray[playercount].team=atoi(tokenArr[0]);
				playersArray[playercount].first=tokenArr[1];
				playersArray[playercount].last=tokenArr[2];
				playersArray[playercount].number=atoi(tokenArr[3]);
				playersArray[playercount].offensive=atoi(tokenArr[4]);
				playersArray[playercount].defensive=atoi(tokenArr[5]);
			}
		}	
	}

	fclose(file);
	return playersArray;
}

Team * initializeTeam(char *Name, Player *players) {
	Team * team = malloc(sizeof(Team));
	team->name = Name;
	team->players = players;
	team->flag = 0;
	return team;
}

Team * game(Team * team1, Team * team2) {
	Team *winner;
	if(team1 == NULL && team2 == NULL) {
		winner = NULL;
		return winner;	
	}
	if(strcmp(team1->name,team2->name) == 0) {
		winner = team1;
	}
	else {
		int defense = 0;
		int offense = 0;
		
		defense += rand() % 100;
		offense += rand() % 100;	
		winner = (defense > offense) ? team1 : team2;
	}
	return winner;
}

Team * tournament(Team **league, int num_teams) {
	Team *winner, *gamewinner;
	int gamescount = 0, totalgames = (num_teams-1);
	int team1, team2;
	if(!(num_teams && (!(num_teams&(num_teams-1)))) == 1) {
		winner=NULL;
		return winner;
	}
	else {
		do {	
			int i = 0;
			team1 = -1, team2 = -1;
			while(i < num_teams) {		
				if(league[i]->flag == -1) {
					i++;
					continue;
				}
				else {
					if(team1 == -1) {
						team1 = i;
					} else {
						team2 = i;
					}
					i++;
				}

				if(team1 != -1 && team2 != -1) {
					gamewinner = game(league[team1], league[team2]);
					if(gamewinner == league[team1]) {
						league[team1]->flag = 1;
						league[team2]->flag = -1;
					}
					else {	
						league[team2]->flag = 1;
						league[team1]->flag = -1;
					}
					gamescount++;
					team1 = -1, team2 = -1;
				}		
			}
		} while(gamescount != totalgames);
		
	}

	for(int j = 0; j < num_teams; j++) {
		if(league[j]->flag == 1)
			winner=league[j];
		league[j]->flag = 0;
	}
	return winner;
}

void deleteTeam(Team *t)
{
	free(t->players);
	free(t);
}
