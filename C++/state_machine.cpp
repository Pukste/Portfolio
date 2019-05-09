#include <iostream>
#define WAIT	1
#define ATTACK	2
#define HEAL	3
#define FLEE	4
/*
	Game world interface.
*/
class Game_World
{
public:
	int state = WAIT;
	static bool is_opponent_nearby()
	{
		std::cout << "Is opponent nearby (0/1)?\n";
		return (bool)get_int_from_stdin();
	}
	
	static bool is_friend_wounded()
	{
		std::cout << "Is friend wounded (0/1)?\n";
		return (bool)get_int_from_stdin();
	}
	
	static bool am_i_wounded()
	{
		std::cout << "Am I wounded (0/1)?\n";
		return (bool)get_int_from_stdin();
	}

	static int get_int_from_stdin()
	{
		int retval;
		std::cin >> retval; 
		return retval; 
	}
};

/*
	Implement your exercises here.
*/
int main()
{
	while (1) {
		switch (state)
		{
		case WAIT:
			if (is_opponent_nearby()) {
				state = ATTACK;
			}
			if (is_friendly_wounded()) {
				state = HEAL;
			}
			break;

		case ATTACK
			if (!is_opponent_nearby()) {
				state = WAIT;
			}
			if (is_friend_wounded()) {
				state = HEAL;
			}
			if (am_i_wounded()) {
				state = FLEE;
			}
			break;

		case HEAL
			if (!is_friendly_wounded()) {
				state = ATTACK;
			}
			if (am_i_wounded()) {
				state = FLEE;
			}
			break;
		case FLEE
			if (!am_i_wounded) {
				state = WAIT;
			}
			break;
		}

	}

	return 0;
}
