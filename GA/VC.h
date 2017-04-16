#ifndef VC_H
#define VC_H


class VC //Virtual Creature
{
public:
    VC();
    double fitness;             //Fitness function of the VC, must be positive! //TODO pls check in the GA every time, if the fitness IS positive. If it negative, set it to 0
    bool valid_fitness;         //Checks if the fitness value is valid. If a mutation happened or a new VC is created, but not tested yet, this value is false;
    virtual void mutate()=0;
    virtual VC *copy()=0;
    virtual VC *mate(VC *partner)=0;
    virtual ~VC();

    bool operator> (const VC &c);  //Overloading the comparisson operators. Compare according to fitness value
    bool operator>= (const VC &c);
    bool operator< (const VC &c);
    bool operator<= (const VC &c);
    bool operator== (const VC &c);
    bool operator!= (const VC &c);

};

#endif // VC_H
