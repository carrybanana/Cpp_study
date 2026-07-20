import std;
import airline_ticket;

int main()
{
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	myTicket.setFrequentFlyerNumber(123456);
	const double cost { myTicket.calculatePriceInDollars() };
	std::println("This ticket will cost ${}", cost);
	if (const auto frequentFlyerNumber{ myTicket.getFrequentFlyerNumber() }) {
		std::println("Frequent flyer number: {}", frequentFlyerNumber.value());
	} else {
		std::println("No frequent flyer number.");
	}

	return 0;
} 
