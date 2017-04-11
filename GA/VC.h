#ifndef VC_H
#define VC_H


class VC //Virtual Creature
{
public:
    VC();
    double fitness;             //Fitness function of the VC, must be positive! //TODO pls check in the GA every time, if the fitness IS positive. If it negative, set it to 0
    bool valid_fitness;         //Checks if the fitness value already has been used for selection. Set to false after selection, and only start the selection when it is true.
    virtual void mutate()=0;
    virtual VC *copy()=0;

    bool operator> (const VC &c);  //Overloading the comparisson operators. Compare according to fitness value
    bool operator>= (const VC &c);
    bool operator< (const VC &c);
    bool operator<= (const VC &c);
};

#endif // VC_H
