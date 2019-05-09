#include <iostream>

/*
	Game world interface.
*/
class Game_World
{
public:

	static void do_run()				{ std::cout << "RUNNING\n";				}
	static void do_shoot()				{ std::cout << "SHOOTING\n";			}
	static void find_target()			{ std::cout << "FINDING TARGET\n";		}
	static void find_safe_area()		{ std::cout << "FINDING SAFE AREA\n";	}
	static void search_shot_source()	{ std::cout << "SEARCHING SOURCE\n";	}
};

/*
	Implement your exercises here.
*/
int main()
{
	int is_shooter_visible;
	int is_shooter_friendly;
	int do_i_have_backup;
	int amount_of_ammo;

	if (is_shooter_visible) {
		if (is_shooter_friendly) {
			find_target();
		}
		else {
			if (amount_of_ammo >= 10) {
				do_shoot();
			}
			else {
				find_safe_area();
			}
		}
	}
	else {
		if (do_i_have_backup > 0) {
			find_target();
		}
		else {
			find_safe_area();
		}
	}

	
	return 0;
}
