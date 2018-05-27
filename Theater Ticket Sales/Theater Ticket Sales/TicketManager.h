#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H
	
#include <string>
using namespace std;




class TicketManager {
	
	struct SeatStructure {
		float ticketPrice;
		char isTicketSold;

		SeatStructure(float initTicketPrice = 0.0, char isSold = 'Y') {
			ticketPrice = initTicketPrice;
			isTicketSold = isSold;
		}
	};

public:
		static const int TOTAL_NUMBER_OF_ROWS = 15;
		static const int TOTAL_NUMBER_OF_COLUMNS = 30;
		float totalProfit = 0.0;
		int currentNumberSeatsAvaliable;

		SeatStructure arrayOfSeatStructures[TOTAL_NUMBER_OF_ROWS][TOTAL_NUMBER_OF_COLUMNS];

		TicketManager();
		~TicketManager();
		string displaySeats(); // pointer to array of seat structures
		string salesReport(int); // pointer to array of seat structures
		string requestTicket(int, int, int); //int numSeatsDesired, int desiredRowNum, int startingSeatNum
		string purchaseTicket(int,int,int); // int priceFromUser
		void updatePurchasedSeats(int, int,int); // int startingSeat, int endingSeat
		int setSeatsAvaliable();


};

#endif
