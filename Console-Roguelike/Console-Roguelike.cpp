#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>


using namespace std;

struct Point {
	int x; int y;
};


enum Type {
	Player,
	Enemy,
	Item
};
enum EnemyType {
	Goblin,
	Guard,
	Gigant
};
enum ItemType {
	Heal,
	DamageBoost
};



struct Entity {
	char symbol;
	Point position;
	Type entityType;

	//enemies
	int hp_enemy;
	EnemyType enemyType;

	//items 
	ItemType itemType;
	int effect;

	//player
	int hp_player = 0;
	int damage = 0;

};

Entity createGoblin(int x, int y) {
	Entity goblin;
	goblin.symbol = 'G';
	goblin.position = { x,y };
	goblin.entityType = Type::Enemy;
	goblin.enemyType = EnemyType::Goblin;
	goblin.hp_enemy = 5;
	return goblin;
}

Entity createGigant(int x, int y) {
	Entity gigant;
	gigant.symbol = 'B';
	gigant.position = { x,y };
	gigant.entityType = Type::Enemy;
	gigant.enemyType = EnemyType::Gigant;
	gigant.hp_enemy = 20;
	return gigant;
}

Entity createGuard(int x, int y) {
	Entity guard;
	guard.symbol = 'I';
	guard.position = { x,y };
	guard.entityType = Type::Enemy;
	guard.enemyType = EnemyType::Guard;
	guard.hp_enemy = 10;
	return guard;
}

Entity createPlayer(int x, int y) {
	Entity player;
	player.symbol = 'P';
	player.position = { x,y };
	player.entityType = Type::Player;
	player.hp_player = 20;
	return player;
}

Entity createHeal(int x, int y) {
	Entity heal;
	heal.symbol = 'H';
	heal.position = { x,y };
	heal.entityType = Type::Item;
	heal.itemType = ItemType::Heal;
	return heal;
}

Entity createDB(int x, int y) {
	Entity damage_boost;
	damage_boost.symbol = 'D';
	damage_boost.position = { x,y };
	damage_boost.entityType = Type::Item;
	damage_boost.itemType = ItemType::DamageBoost;
	return damage_boost;
}





const int MAX_GOBLINS = 3;
int goblins_count = 0;
Entity goblins[MAX_GOBLINS];

const int MAX_GUARDS = 2;
int guards_count = 0;
Entity guards[MAX_GUARDS];

const int MAX_GIGANTS = 2;
int gigants_count = 0;
Entity gigants[MAX_GIGANTS];



const int width = 20;
const int height = 7;

char map[width][height];
char background = '~';



void spawnGoblin() {
	goblins_count = 1 + rand() % MAX_GOBLINS;

	for (int i = 0; i < goblins_count; i++) {
		goblins[i] = createGoblin(4 + rand() % (width - 4 + 1), rand() % height);

	}

}

void spawnGuard() {
	guards_count = 1 + rand() % 2;

	for (int i = 0; i < guards_count; i++) {
		guards[i] = createGuard(4 + rand() % (width - 4 + 1), rand() % height);

	}
}

void spawnGigant() {
	gigants_count = 1 + rand() % 2;

	for (int i = 0; i < gigants_count; i++) {
		gigants[i] = createGigant(4 + rand() % (width - 4 + 1), rand() % height);

	}

}


void draw(Entity player) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			char toDraw = background;

			if (x == player.position.x && y == player.position.y) {
				toDraw = player.symbol;
			}
			else {
				
				for (int i = 0; i < goblins_count; i++) {
					if (x == goblins[i].position.x && y == goblins[i].position.y) {
						toDraw = goblins[i].symbol;
						break;
					}
				}

				
				for (int i = 0; i < guards_count; i++) {
					if (x == guards[i].position.x && y == guards[i].position.y) {
						toDraw = guards[i].symbol;
						break;
					}
				}

				
				for (int i = 0; i < gigants_count; i++) {
					if (x == gigants[i].position.x && y == gigants[i].position.y) {
						toDraw = gigants[i].symbol;
						break;
					}
				}
			}

			map[x][y] = toDraw;
			cout << map[x][y];
		}
		cout << endl;
	}
}

void playerMove(Entity& player) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': player.position.x--; break;
		case 'd': player.position.x++; break;
		case 'w' && 'ö': player.position.y--; break;
		case 's': player.position.y++; break;
		}
	}

	if (player.position.x >= width) {
		player.position.x--;
	}
	if (player.position.x < 0) {
		player.position.x++;
	}
	if (player.position.y >= height) {
		player.position.y--;
	}
	if (player.position.y < 0) {
		player.position.y++;
	}
	::Sleep(50);

}

int main() {
	srand(time(NULL));
	Entity player = createPlayer(0, 3);

	
	spawnGuard();

	spawnGoblin();

	spawnGigant();
	
	bool isRuning = true;

	while (isRuning) {
		system("cls");

		draw(player);

		playerMove(player);
		
		
		
		
	}

	

	return 0;
}
