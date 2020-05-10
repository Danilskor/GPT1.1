#include "Lab3_execute.h"
#include "Common/Consts/Consts.h"

void main()
{
	setlocale(LC_ALL, "ru");

	DemoBook();
	system("pause");

	DemoRoute();
	system("pause");

	DemoRectangleWithPoint();
	system("pause");

	DemoFlightWithTime();
	system("pause");

	DemoBand();
}

void DemoBook()
{
	string name;
	int year;
	int numberOfAuthors;
	int pages;
	string* authors;
	int arraysSize = 1;
	Book* books = new Book[arraysSize];

	for (int i = 0; i < arraysSize; i++)
	{
		cout << "����� �" << i + 1 << endl;
		ReadBookFromConsole(name, year, pages, numberOfAuthors, authors);
		Book newBook(name, year, pages, numberOfAuthors, authors);
		books[i] = newBook;
	}

	for (int i = 0; i < arraysSize; i++)
	{
		WriteBookInConsole(books[i]);
	}

	cout << endl << "��� ������ �����, ������� ��� ������: ";
	cin.clear();

	string* author = new string;
	getline(cin, *author);
	Book* book = FindBookByAuthor(books, arraysSize, *author);

	if (book != nullptr)
	{
		cout << "����� ������: ";
		WriteBookInConsole(*book);
	}
	else
	{
		cout << "��� ����� � ����� �������.";
	}

	delete[] books;
	delete author;
}

void WriteBookInConsole(Book& book)
{
	for (int i = 0; i < book.GetAutorsCount() - 1; i++)
	{
		cout << book.GetAuthors()[i] << ", ";
	}
	cout << book.GetAuthors()[book.GetAutorsCount() - 1] << " ";
	cout << book.GetName() << ". ";
	cout << book.GetYear() << ". ";
	cout << "- " << book.GetPages() << "c." << endl;
}

void ReadBookFromConsole(string& name, int& year, int& pages, int&
	authorsCount, string*& authors)
{
	cout << "������� �������� �����:";
	cin.clear();
	getline(cin, name);

	cout <<"������� ��� �������:";
	year = ReadValueInRange(1, 2020);

	cout <<"������� ���������� �������:";
	pages = ReadValueInRange(1, SHRT_MAX);

	cout <<"������� ���������� �������:";
	authorsCount = ReadValueInRange(1, 10);
	authors = new string[authorsCount];

	for (int i = 0; i < authorsCount; i++)
	{
		cin.clear();
		cout << "������� ������ �" << i + 1 << ":";
		getline(cin, authors[i]);
	}
	cout << endl;
}

Book* FindBookByAuthor(Book* books, int booksCount, string author)
{
	Book* book;
	for (int i = 0; i < booksCount; i++)
	{
		if ((book = books[i].FindAuthor(author)) != nullptr)
		{
			return book;
		}
	}
	return nullptr;
}

void DemoRoute()
{
	int number;
	int timeAveregeMinutes;
	int frequencyMinutes;
	int stopsCount;
	string* stops;
	int arraysSize = 3;
	Route* routes = new Route[arraysSize];

	for (int i = 0; i < arraysSize; i++)
	{
		cout << "���� �" << i + 1 << endl;
		ReadRouteFromConsole(number,timeAveregeMinutes,frequencyMinutes,stopsCount,
		stops);
		Route newRoute(number, timeAveregeMinutes, frequencyMinutes, stopsCount,
			stops);
		routes[i] = newRoute;
	}

	for (int i = 0; i < arraysSize; i++)
	{
		WriteRouteInCounsole(routes[i]);
	}

	cout << endl << "������� �������� ���������: ";
	string name;
	cin.clear();

	getline(cin, name);
	Route* route = FindRouteByStop(routes, arraysSize, name);

	if (route != nullptr)
	{
		cout << "���� � ������ ����������: ";
		WriteRouteInCounsole(*route);
	}
	else
	{
		cout << "��� ����� � ����� ����������." << endl;
	}

	delete[] routes;
	//delete[] stops;
}

void WriteRouteInCounsole(Route& route)
{
	for (int i = 0; i < route.GetStopsCount() - 1; i++)
	{
		cout << route.GetStops()[i] << " - ";
	}
	cout << route.GetStops()[route.GetStopsCount() - 1] << ". ";
	cout << "�" << route.GetNumber() << " ����������������� " << route.GettimeAveregeMinutes() <<
		" ���. " << " �������: " << route.GetFrequencyMinutes() <<
		" ���." << endl;
}

void ReadRouteFromConsole(int& number, int& timeAveregeMinutes,
	int& frequencyMinutes, int& stopsCount, string*& stops)
{
	cout << "������� ��������� ������: ";
	number = ReadValueInRange<int>(0, INT_MAX);

	cout << "������� ����� ����� � �������:";
	timeAveregeMinutes = ReadValueInRange(1, 60);

	cout << "������� ������� ���������� �������� � �������:";
	frequencyMinutes = ReadValueInRange(1, 100);

	cout << "������� ���������� ��������� �����:";
	stopsCount = ReadValueInRange(1, 10);

	stops = new string[stopsCount];
	for (int i = 0; i < stopsCount; i++)
	{
		cout << "������� �������� ��������� �" << i + 1 << ": ";
		cin.clear();
		getline(cin, stops[i]);
	}
}

Route* FindRouteByStop(Route* routes, int routesCount, string stopName)
{
	Route* route;
	for (int i = 0; i < routesCount; i++)
	{
		if ((route = routes[i].FindStop(stopName)) != nullptr)
		{
			return route;
		}
	}
	return nullptr;
}

void DemoRectangleWithPoint()
{
	int rectangelArraySize = 5;
	cRectangle* rectangles = new cRectangle[rectangelArraySize];
	rectangles[0] = cRectangle(3.1, 5.4, &Point(66.6, -3));
	rectangles[1] = cRectangle(12.1, 14.6, &Point(77.7, -77.7));
	rectangles[2] = cRectangle(2.8, 2.9, &Point(0, 0));
	rectangles[3] = cRectangle(3.9, 9.3, &Point(-23.2, 32.3));
	rectangles[4] = cRectangle(100, 10, &Point(0.1, 0.1));

	for (int i = 0; i < rectangelArraySize; i++ )
	{
		cout << "X = " << rectangles[i].GetCentre()->GetX() << "; Y = " <<
			rectangles[i].GetCentre()->GetY() << "; ����� = " <<
			rectangles[i].Getlength() << "; ������ = " <<
			rectangles[i].GetWidth() << endl;
	}

	double sumX = 0;
	double sumY = 0;
	for (int i = 0; i < rectangelArraySize; i++)
	{
		sumX = sumX + rectangles[i].GetCentre()->GetX();
		sumY = sumY + rectangles[i].GetCentre()->GetY();
	}
	cout << "Xcenter = " << sumX / 5 << "; Ycenter = " << sumY / 5;

	delete[] rectangles;
}

void DemoFlightWithTime()
{
	int flightsArraySize = 5;
	cFlight* flights = new cFlight[flightsArraySize];

	flights[0] = cFlight(rand() % 1000000, "������������", "�����",
		&cTime(2020, 9, 28, 16, 5), &cTime(2020, 9, 28, 20, 5));

	flights[1] = cFlight(rand() % 1000000, "�����", "������������",
		&cTime(2020, 9, 28, 20, 5), &cTime(2020, 9, 29, 0, 5));

	flights[2] = cFlight(rand() % 1000000, "�����������", "������",
		&cTime(2020, 11, 10, 11, 16), &cTime(2020, 7, 22, 22, 10));

	flights[3] = cFlight(rand() % 1000000, "�����������", "�����",
		&cTime(2020, 1, 2, 3, 4), &cTime(2020, 9, 8, 7, 6));

	flights[4] = cFlight(rand() % 1000000, "����", "����",
		&cTime(2020, 6, 6, 6, 6), &cTime(2020, 7, 7, 7, 7));

	for (int i = 0; i < flightsArraySize; i++)
	{
		WriteFlightToConsole(&flights[i]);
		cout << endl;
	}
	cout << endl;

	cout << "���� ";
	WriteFlightToConsole(&flights[1]);
	cout << " ����� �����: ";
	WriteTimeToConsole(&GetFlightTimeMinutes(&flights[1]));
	cout << endl;

	delete[] flights;
}

void WriteFlightToConsole(cFlight* flight)
{
	cout << flight->GetNumber() << " " <<
		flight->GetdeparturePoint() << " - "
		<< flight->GetarrivalPoint() << " ����� ";
	WriteTimeToConsole(flight->GetTimeOfDeparture());
	cout << " �������� ";
	WriteTimeToConsole(flight->GetTimeOFArrival());
}

void WriteTimeToConsole(cTime* time)
{
	cout << time->GetDay() << '.' << time->GetMonth() << '.' << 
		time->GetYear() << ' ' << time->GetHour() << ':' << time->GetMinute();
}

cTime GetFlightTimeMinutes(cFlight* flight)
{
	cTime timeInFlight(0,0,0,0,0);

	int days = flight->GetTimeOFArrival()->GetDay() - 
		flight->GetTimeOfDeparture()->GetDay();

	int hours = flight->GetTimeOFArrival()->GetHour() - 
		flight->GetTimeOfDeparture()->GetHour();

	int minutes = flight->GetTimeOFArrival()->GetMinute() - 
		flight->GetTimeOfDeparture()->GetMinute();

	if (days != 0)
	{
		hours = MAX_HOUR + hours;
		minutes = MAX_MINUTES - minutes;
		if (minutes >= MAX_MINUTES)
		{
			hours++;
			minutes = minutes - 60;
		}
		if (hours >= MAX_HOUR)
		{
			days = 1;
			hours = hours - MAX_HOUR;
			timeInFlight.SetDay(days);
			timeInFlight.SetHour(hours);
			timeInFlight.SetMinute(minutes);
			return timeInFlight;
		}
		timeInFlight.SetHour(hours);
		timeInFlight.SetMinute(minutes);
		return timeInFlight;
	}
	else
	{
		timeInFlight.SetHour(hours);
		timeInFlight.SetMinute(minutes);
		return timeInFlight;
	}
}

void DemoBand()
{
	int firstSongsArraySize = 3;
	cSong* songsFirst = new cSong[firstSongsArraySize];

	songsFirst[0] = cSong(255, "Say it", Rock);
	songsFirst[1] = cSong(234, "������", Pop);
	songsFirst[2] = cSong(457, "keep talking", Dubstep);
	

	int secondSongsArraySize = 4;
	cSong* songsSecond = new cSong[secondSongsArraySize];

	songsSecond[0] = cSong(142, "Mutter", Rock);
	songsSecond[1] = cSong(423, "Genesis", Pop);
	songsSecond[2] = cSong(453, "Aaa", Jazz);
	songsSecond[3] = cSong(453, "Ludens", Rock);
	

	int thirdSongsArraySize = 5;
	cSong* songsThird = new cSong[thirdSongsArraySize];

	songsThird[0] = cSong(453, "Blure", Blues);
	songsThird[1] = cSong(456, "Special Needs", Rock);
	songsThird[2] = cSong(356, "Blues", Blues);
	songsThird[3] = cSong(321, "Gods", Jazz);
	songsThird[4] = cSong(251, "Trip Switch", Dubstep);

	int albumArraySize = 3;
	cAlbum* albums = new cAlbum[3];

	albums[0].SetName("Super");
	albums[0].SetYear(1999);
	albums[0].SetSong(songsFirst, 3);

	albums[1].SetName("Massive");
	albums[1].SetYear(2001);
	albums[1].SetSong(songsSecond, 4);

	albums[2].SetName("Black hole");
	albums[2].SetYear(2019);
	albums[2].SetSong(songsThird, 5);

	cBand band("30 yeconds", "��������", albums, 3);
	
	WriteBandInfoToConsole(&band);

	int songCount = 0;
	cout << endl << "��� �����:" << endl;
	cSong** allSongs = band.GetAllSongs(songCount);
	for (int i = 0; i < songCount; i++)
	{
		WriteSongToConsole(allSongs[i]);
		cout << endl;
	}

	cout << endl << "���: " << endl;
	cSong** allGenreSongs = band.GetAllSongsGenre(songCount, Rock);
	for (int i = 0; i < songCount; i++)
	{
		WriteSongToConsole(allGenreSongs[i]);
		cout << endl;
	}

	cout << endl << "����� ����� <<������>>: " << endl;
	WriteSongToConsole(band.FindSong("������"));

	cout << endl <<"����� ������� � ������ <<������>>: " << endl;
	WriteAlbumToConsole(band.FindAlbum("������"));
	cout << endl;

	delete[] songsFirst;
	delete[] songsSecond;
	delete[] songsThird;
}

void WriteBandInfoToConsole(cBand* band)
{
	cout << "������ " << band->GetName() << endl;
	for (int i = 0; i < band->GetauthorsCount(); i++)
	{
		WriteAlbumToConsole(&band->GetAlbum()[i]);
	}
}

void WriteSongToConsole(cSong* song)
{
	cout << "\"" << song->GetName() << "\"" << " ���� ";
	WriteSongGenreToConsole(song->GetGenre());
	cout << " �����������������: " << song->GetDurationSeconds();
}

void WriteSongsToConsole(cSong* song, int songCount)
{
	for (int i = 0; i < songCount; i++)
	{
		WriteSongToConsole(&song[i]);
		cout << endl;
	}
}

void WriteAlbumToConsole(cAlbum* album)
{
	cout << "������ ";
	cout << album->GetName();
	cout << endl;
	WriteSongsToConsole(album->GetSong(),
		album->GetSongCounter());
	cout << endl;
}
