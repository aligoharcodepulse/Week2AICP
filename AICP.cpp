#include <iostream>
using namespace std;

int main()
{
    int numOfTrips = 4, numOfCoaches = 6, seatsInCoach = 80, ticketPrice = 25, numberOfPassengers{};
    int train1_seats = 480, train2_seats = 480, train3_seats = 480, train4_seats = 640, amountToPay;
    int ticketPurchase{}, returnTrip{}, departureTrip{};
    string trainStatus[] = { "", "", "", "" }; // Array to store train status
    int totalPassengers[8] = { 0 };            // Array to store total passengers for each journey
    int totalMoney[8] = { 0 };                 // Array to store total money taken for each journey
    int totalDayPassengers = 0;                // Total number of passengers for the day
    int totalDayMoney = 0;                     // Total money taken for the day
    int maxPassengers = 0;                     // Maximum passengers for a single journey
    int maxPassengersJourney = 0;              // Journey with the most passengers

    cout << "\n Train 1 Foot to Mountain time is 9:00";
    cout << "\n Train 1 Mountain to Foot time is 10:00";
    cout << "\n Train 2 Foot to Mountain time is 11:00";
    cout << "\n Train 2 Mountain to Foot time is 12:00";
    cout << "\n Train 3 Foot to Mountain time is 13:00";
    cout << "\n Train 3 Mountain to Foot time is 14:00";
    cout << "\n Train 4 Foot to Mountain time is 15:00";
    cout << "\n Train 4 Mountain to Foot time is 16:00";

    cout << "\nNumber of Passengers: " << numberOfPassengers;
    cin >> numberOfPassengers;

    cout << "Ticket Purchase: " << ticketPurchase;
    cin >> ticketPurchase;

    cout << "\nEnter Return Trip(1-4): " << returnTrip;
    cin >> returnTrip;

    cout << "\nEnter Departure Trip(1-4): " << departureTrip;
    cin >> departureTrip;

    if (returnTrip >= 1 && returnTrip <= 4)
    {
        cout << "Valid return trip ";
        if (trainStatus[returnTrip - 1] != "Closed")
        {
            amountToPay = ticketPurchase * ticketPrice;
            cout << "\n Amount To Pay: " << amountToPay;
            train1_seats -= ticketPurchase; // Adjust the available seats

            // Update total passengers and total money for the journey
            totalPassengers[returnTrip - 1]++;
            totalMoney[returnTrip - 1] += amountToPay;

            // Update total passengers and total money for the day
            totalDayPassengers += numberOfPassengers;
            totalDayMoney += amountToPay;

            // Update maximum passengers for a single journey
            if (numberOfPassengers > maxPassengers)
            {
                maxPassengers = numberOfPassengers;
                maxPassengersJourney = returnTrip;
            }
        }
        else
        {
            cout << "Train is closed.";
        }
    }

    else if (departureTrip >= 1 && departureTrip <= 4)
    {
        cout << "Valid Departure Trip";
        if (trainStatus[departureTrip - 1] != "Closed")
        {
            amountToPay = ticketPurchase * ticketPrice;
            cout << "\n Amount To Pay: " << amountToPay;
            train1_seats -= ticketPurchase; // Adjust the available seats

            // Update total passengers and total money for the journey
            totalPassengers[departureTrip + 3]++;
            totalMoney[departureTrip + 3] += amountToPay;

            // Update total passengers and total money for the day
            totalDayPassengers += numberOfPassengers;
            totalDayMoney += amountToPay;

            // Update maximum passengers for a single journey
            if (numberOfPassengers > maxPassengers)
            {
                maxPassengers = numberOfPassengers;
                maxPassengersJourney = departureTrip + 3;
            }
        }
        else
        {
            cout << "Train is closed.";
        }
    }

    else if ((returnTrip < 1 && returnTrip > 4) || (departureTrip < 1 && departureTrip > 4))
    {
        cout << "You Entered Invalid Trip";
    }

    else if (returnTrip == departureTrip)
    {
        cout << "Return trip cannot be the same as the departure trip. Please choose different trips for return and departure.";
    }


    if (numberOfPassengers > 10 && numberOfPassengers < 80)
    {
        amountToPay = ticketPrice * (numberOfPassengers - 1);
        cout << "Total Amount Will Be: " << amountToPay;

        // Update total passengers and total money for the journey
        totalPassengers[returnTrip - 1]++;
        totalMoney[returnTrip - 1] += amountToPay;

        // Update total passengers and total money for the day
        totalDayPassengers += numberOfPassengers;
        totalDayMoney += amountToPay;

        // Update maximum passengers for a single journey
        if (numberOfPassengers > maxPassengers)
        {
            maxPassengers = numberOfPassengers;
            maxPassengersJourney = returnTrip;
        }
    }
    else
    {
        amountToPay = ticketPrice * numberOfPassengers;

        // Update total passengers and total money for the journey
        totalPassengers[returnTrip - 1]++;
        totalMoney[returnTrip - 1] += amountToPay;

        // Update total passengers and total money for the day
        totalDayPassengers += numberOfPassengers;
        totalDayMoney += amountToPay;

        // Update maximum passengers for a single journey
        if (numberOfPassengers > maxPassengers)
        {
            maxPassengers = numberOfPassengers;
            maxPassengersJourney = returnTrip;
        }
    }

    // Display updated train status and totals
    for (int i = 0; i < 4; ++i)
    {
        if (trainStatus[i] == "Closed")
        {
            cout << "\nTrain " << i + 1 << ": Closed";
        }
        else
        {
            cout << "\nTrain " << i + 1 << ": " << trainStatus[i] << " tickets available";
        }
    }

    // Display totals
    for (int i = 0; i < 8; ++i)
    {
        cout << "\nJourney " << i + 1 << ": Total Passengers = " << totalPassengers[i] << ", Total Money =" << totalMoney[i];
    }

    // Display total passengers and total money for the day
    cout << "\nTotal Day Passengers: " << totalDayPassengers;
    cout << "\nTotal Day Money: " << totalDayMoney;

    // Display journey with the most passengers for the day
    cout << "\nJourney with the Most Passengers: Journey " << maxPassengersJourney << " with " << maxPassengers << " passengers";

    return 0;
}
