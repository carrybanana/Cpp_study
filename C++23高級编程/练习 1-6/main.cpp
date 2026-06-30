import std;
import airline_ticket;

int main()
{
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	const double cost{ myTicket.calculatePriceInDollars() };
	std::println("This ticket will cost ${}", cost);
} 
