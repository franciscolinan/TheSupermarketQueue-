#include <iostream>
#include <vector>
#include <algorithm>

/*
There is a queue for the self-checkout tills at the supermarket. Your task is write a function to calculate 
the total time required for all the customers to check out!

input
	customers: an array of positive integers representing the queue. Each integer represents a customer, and 
	its value is the amount of time they require to check out.
	n: a positive integer, the number of checkout tills.

output
	The function should return an integer, the total time required.

clarifications
	There is only ONE queue serving many tills, and
	The order of the queue NEVER changes, and
	The front person in the queue (i.e. the first element in the array/list) proceeds to a till as soon as it becomes free.

N.B. You should assume that all the test input will be valid, as specified above
*/

auto QueueTime(const std::vector<unsigned int> customers_time, const unsigned int n) -> int
{
	const std::unique_ptr<unsigned int[]> tills = std::make_unique<unsigned int[]>(n);

	for (unsigned int customer_time : customers_time)
	{
		// Add current customer time to the lowest time till
		//
		*std::min_element(tills.get(), tills.get() + n) += customer_time;
	}

	return *std::max_element(tills.get(), tills.get() + n);
}

auto main() -> int
{
	const std::vector<unsigned int> customers_time = { 2, 3, 10};
	const unsigned int n = 2;

	std::cout << "Queue time: " << QueueTime(customers_time, n) << std::endl;
}