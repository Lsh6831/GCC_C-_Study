#include "Sorceress.h"


Sorceress::Sorceress(const string& name, bool isHardcore)
    :Player(name, "Barbarian",isHardcore,30,40,40,90){}

int Sorceress::Attack() const
{
    return (int)(energy*0.8f);
}
