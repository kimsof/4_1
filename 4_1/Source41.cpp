#include <iostream>
#include <chrono>
#include <iomanip>
#include <thread>
#include <vector>
#include <array>
#include <set>
#include <algorithm>
#include <random>  
#include <ctime> 

class Timer
{
	using watch_t = std::chrono::steady_clock;
	using timepoint_t = watch_t::time_point;

public:
	Timer() : m_begin(watch_t::now()), time(0)
	{
		std::cout << "Timer_CTOR" << std::endl;
	}
	~Timer() noexcept
	{
		auto end = watch_t::now();
		std::cout << "Timer stopped, ";
		if (working)
			time += std::chrono::duration_cast <std::chrono::milliseconds> (end - m_begin);
		std::cout << time.count();
		std::cout << " milliseconds passed." << std::endl;
	}
	void pause()
	{
		auto end = watch_t::now();
		working = false;
		time += std::chrono::duration_cast <std::chrono::milliseconds> (end - m_begin);
		std::cout << "Timer paused, " << time.count() << " milliseconds passed." << std::endl;

	}
	void resume()
	{
		working = true;
		m_begin = watch_t::now();
		std::cout << "Timer resumed" << std::endl;
	}
private:
	timepoint_t m_begin;
	std::chrono::milliseconds time;
	bool working = true;
};


int main()
{
	int number;
	std::cin >> number;

		std::vector <int> vector;
		std::mt19937 gen(time(0));
		std::uniform_int_distribution<> uid(0,100);
		for (int i = 0; i < number; i++) {
			vector.push_back(uid(gen));
		}
		

		std::array <int, 1000> array;
		for (int i = 0; i < array.size(); i++) {
			array[i] = vector[i];
		}
		
		{
			Timer timer_for_vector;
			std::sort(vector.begin(), vector.end());
		}

		{
			Timer timer_for_array;
			std::sort(array.begin(), array.end());
		}

		{
			Timer timer_for_set;
			std::set <int> set;
			for (int i = 0; i < number; i++) {
			set.insert(vector[i]);
		}
	}
	system("pause");
	return 0;
}
