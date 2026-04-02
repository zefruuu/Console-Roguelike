#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>


using namespace std;

bool isRuning = true;

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
	int damage_enemy;
	EnemyType enemyType;

	//items 
	ItemType itemType;
	int effect;

	//player
	int hp_player = 0;
	int damage_player = 0;

};

Entity createGoblin(int x, int y) {
	Entity goblin;
	goblin.symbol = 'G';
	goblin.position = { x,y };
	goblin.entityType = Type::Enemy;
	goblin.enemyType = EnemyType::Goblin;
	goblin.damage_enemy = 5;
	goblin.hp_enemy = 5;
	return goblin;
}

Entity createGigant(int x, int y) {
	Entity gigant;
	gigant.symbol = 'B';
	gigant.position = { x,y };
	gigant.entityType = Type::Enemy;
	gigant.enemyType = EnemyType::Gigant;
	gigant.damage_enemy = 20;
	gigant.hp_enemy = 20;
	return gigant;
}

Entity createGuard(int x, int y) {
	Entity guard;
	guard.symbol = 'I';
	guard.position = { x,y };
	guard.entityType = Type::Enemy;
	guard.enemyType = EnemyType::Guard;
	guard.damage_enemy = 10;
	guard.hp_enemy = 10;
	return guard;
}

Entity createPlayer(int x, int y) {
	Entity player;
	player.symbol = 'P';
	player.position = { x,y };
	player.entityType = Type::Player;
	player.hp_player = 20;
	player.damage_player = 5;
	return player;
}

Entity createHeal(int x, int y) {
	Entity heal;
	heal.symbol = 'H';
	heal.position = { x,y };
	heal.entityType = Type::Item;
	heal.itemType = ItemType::Heal;
	heal.effect = 5;
	return heal;
}

Entity createDB(int x, int y) {
	Entity damage_boost;
	damage_boost.symbol = 'D';
	damage_boost.position = { x,y };
	damage_boost.entityType = Type::Item;
	damage_boost.itemType = ItemType::DamageBoost;
	damage_boost.effect = 5;
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

const int MAX_HEALS = 4;
int heals_count = 0;
Entity heals[MAX_HEALS];

const int MAX_DAMAGE_BOOST = 4;
int db_count = 0;
Entity damage_boosts[MAX_DAMAGE_BOOST];



const int width = 20;
const int height = 7;

char map[width][height];
char background = '~';

int kills;


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

void spawnHeal() {
	heals_count = 1 + rand() % 3;

	for (int i = 0; i < heals_count; i++) {
		heals[i] = createHeal(4 + rand() % (width - 4 + 1), rand() % height);

	}

}

void spawnDamageBoost() {
	db_count = 1 + rand() % 3;

	for (int i = 0; i < db_count; i++) {
		damage_boosts[i] = createDB(4 + rand() % (width - 4 + 1), rand() % height);

	}

}

void drawStats(Entity& player) {
	cout << "Your Statistics: " << endl;
	cout << "Health: " << player.hp_player << endl;
	cout << "Damage: " << player.damage_player << endl;
	cout << "Kills: " << kills << endl;
	cout << endl;
}


void draw(Entity player) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			char toDraw = background;

			if (x == player.position.x && y == player.position.y) {
				toDraw = player.symbol;
			}
			else {
				for (int i = 0; i < heals_count; i++) {
					if (x == heals[i].position.x && y == heals[i].position.y) {
						toDraw = heals[i].symbol;
						break;
					}
				}

				for (int i = 0; i < db_count; i++) {
					if (x == damage_boosts[i].position.x && y == damage_boosts[i].position.y) {
						toDraw = damage_boosts[i].symbol;
						break;
					}
				}


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
		case 'w': player.position.y--; break;
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
void takeItem(Entity& player) {
	for (int i = 0; i < heals_count; i++) {
		if (player.position.x == heals[i].position.x && player.position.y == heals[i].position.y) {
			player.hp_player += heals[i].effect;
			for (int j = i; j < heals_count - 1; j++) {
				heals[j] = heals[j + 1];
			}

				heals_count--;
				i--;
			
		}
	}
	for (int i = 0; i < db_count; i++) {
		if (player.position.x == damage_boosts[i].position.x && player.position.y == damage_boosts[i].position.y) {
			player.damage_player += damage_boosts[i].effect;
			for (int j = i; j < db_count - 1; j++) {
				damage_boosts[j] = damage_boosts[j + 1];
			}

			db_count--;
			i--;

		}
	}
}

void fight(Entity& player) {
	for (int i = 0; i < goblins_count; i++) {
		if (player.position.x == goblins[i].position.x && player.position.y == goblins[i].position.y) {
			goblins[i].hp_enemy -= player.damage_player;
			player.hp_player -= goblins[i].damage_enemy;

			if (player.hp_player > 0 && goblins[i].hp_enemy <= 0) {
				for (int j = i; j < goblins_count - 1; j++) {
					goblins[j] = goblins[j + 1];
				}

				kills++;
				goblins_count--;
				i--;
			}
		}
	}
		for (int i = 0; i < guards_count; i++) {
			if (player.position.x == guards[i].position.x && player.position.y == guards[i].position.y) {
				guards[i].hp_enemy -= player.damage_player;
				player.hp_player -= guards[i].damage_enemy;

				if (player.hp_player > 0 && guards[i].hp_enemy <= 0) {
					for (int j = i; j < guards_count - 1; j++) {
						guards[j] = guards[j + 1];
					}

					kills++;
					guards_count--;
					i--;
				}
			}
		}
		for (int i = 0; i < gigants_count; i++) {
			if (player.position.x == gigants[i].position.x && player.position.y == gigants[i].position.y) {
				gigants[i].hp_enemy -= player.damage_player;
				player.hp_player -= gigants[i].damage_enemy;

				if (player.hp_player > 0 && gigants[i].hp_enemy <= 0) {
					for (int j = i; j < gigants_count - 1; j++) {
						gigants[j] = gigants[j + 1];
					}

					kills++;
					gigants_count--;
					i--;
				}
			}
		}

	if (player.hp_player <= 0) {
		isRuning = false;
		cout << "You Dead!";
		::Sleep(200);
	}
}


int main() {
	srand(time(NULL));
	Entity player = createPlayer(0, 3);


	spawnGuard();

	spawnGoblin();

	spawnGigant();

	spawnHeal();

	spawnDamageBoost();


	while (isRuning) {
		system("cls");

		drawStats(player);

		draw(player);

		playerMove(player);

		fight(player);

		takeItem(player);





	}



	return 0;
}
