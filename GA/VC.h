#ifndef VC_H
#define VC_H


class VC
{
public:
    VC();
    double fitness;
    virtual void mutate()=0;
    virtual VC copy()=0;
};

#endif // VC_H
