﻿#include "Album.h"

Album::Album()
{
	this->SetSong(nullptr, 0);
}

void Album::SetName(string name)
{
	this->_name = name;
}

void Album::SetYear(int year)
{
	if (year < 1 || year > GetCurrentYear())
	{
		throw exception("Year must be in range from 1 to currentYear");
	}
	this->_year = year;
}
// TODO: массивы в множественном числе!
void Album::SetSong(Song* songs, int songsCount) // TODO: Count, а не Counter. Counter - так именуются совсем другие объекты
{
	this->_songs = new Song[songsCount];
	this->_songsCount = songsCount;
	for (int i = 0; i < songsCount; i++)
	{
		this->_songs[i] = songs[i];
	}
}
// TODO: множ. число
Album::Album(string name, int year, Song* songs, int songsCount)
{
	this->SetName(name);
	this->SetYear(year);
	this->SetSong(songs, songsCount);
}

string Album::GetName()
{
	return this->_name;
}
// TODO: грам. ошибка
int Album::GetYear()
{
	return this->_year;
}
// TODO: именование
Song* Album::GetSong()
{
	return this->_songs;
}
// TODO: именование
int Album::GetSongsCount()
{
	return this->_songsCount;
}

Song* Album::FindSong(string songName)
{
	for (int i = 0; i < this->_songsCount; i++)
	{
		if (this->GetSong()[i].GetName() == songName)
		{
			return &this->GetSong()[i];
		}
	}
	return nullptr;
}

Album::~Album()
{
	delete[] this->_songs;
}
