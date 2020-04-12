#include "SimpleFC.h"

FC::FC()
{
    size = 30;
    films = new Film[size];
    noOfFilms = 0;


}

FC::FC(const FC &fcToCopy)
{

    noOfFilms = fcToCopy.noOfFilms;
    size = fcToCopy.size;

    if(noOfFilms > 0)
    {
        //films = new  Film[noOfFilms];
        for(unsigned int i = 0; i < noOfFilms; i++)
        {
            films[i] = fcToCopy.films[i];
        }
    }
    else
    {
        films = NULL;
    }
}
void FC::operator=(const FC &right)
{
    size = right.size;
    if(noOfFilms != right.noOfFilms )
    {
        noOfFilms = right.noOfFilms;
        if(noOfFilms > 0)
        {
            delete [] films;
            films = new Film[noOfFilms];
        }
        else
        {
            films = NULL;
        }
    }
    for(unsigned int i = 0; i < noOfFilms; i++)
    {
        films[i] = right.films[i];
    }

}
unsigned int FC::getFilms(Film *&allFilms) const
{

    allFilms = new Film[noOfFilms];

    for(unsigned int i = 0; i < noOfFilms; i++)
    {
        allFilms[i] = films[i];
       // cout<<allFilms[i].getTitle() <<", "<<allFilms[i].getYear()<<", "<<allFilms[i].getDirector() <<", "<<allFilms[i].getDuration()<< endl;
    }

   // delete [] allFilms;
    return noOfFilms;
}

bool FC::addFilm(const string fTitle, const string fDirector,
                 const unsigned int fYear,
                 const unsigned int fDuration)
{
    if(noOfFilms >= 0)
    {
        Film film(fTitle, fDirector, fYear, fDuration);
        films[noOfFilms] = film;
        noOfFilms++;
        return true;
    }

    return false;
}

bool FC::removeFilm(const string fTitle, const string fDirector){

    bool a = false;
    if(noOfFilms >= 1)
    {
        for(unsigned int i = 0; i < noOfFilms; i++)
        {
                if(films[i].getTitle() == fTitle && films[i].getDirector() == fDirector )
                {
                    for(unsigned int k = i; k < noOfFilms; k++){
                    films[k] = films[k + 1];

                    }
                     a = true;
                    noOfFilms--;
                }
        }
        return a;
    }
    return a;
}



FC::~FC()
{
    if(films)
    {
        delete[] films;
    }

}
