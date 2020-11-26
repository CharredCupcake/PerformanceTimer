#pragma once
#include <iostream>
#include <string>
#include <chrono>

class ChronoTimer
{
public:

	ChronoTimer(const char* name, std::ostream& out) :
		m_wasStopped(false),
		m_out(&out),
		m_name(name)
	{
		m_start = std::chrono::high_resolution_clock::now();
	};
	~ChronoTimer() { stop(); };

	void stop()
	{
		if (!m_wasStopped)
		{
			m_end = std::chrono::high_resolution_clock::now();
			m_elapsed = std::chrono::time_point<std::chrono::nanoseconds>(m_end - m_start);
		}

		m_wasStopped = true;

		*m_out << "Name:\n";
		*m_out << m_name << '\n';
		*m_out << "Time Elapsed:\n";
		*m_out << m_elapsed.time_since_epoch().count() / 1000000 << " ms\n";
	};

private:

	std::ostream* m_out;
	std::string m_name;
	bool m_wasStopped;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_end;
	std::chrono::time_point<std::chrono::nanoseconds> m_elapsed;
};