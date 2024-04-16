//--------------- temperature.h ---------------

class temperature{
public:

    // constructor with parameters. default degree = 0.0, default scale = 'C'
    temperature(double x=0.0, char y='C');

    // accessors
    void Show() const;
    double GetDegrees() const;
    char GetScale() const;
    int Compare(const temperature& d) const;

    // mutators
    void Input();
    bool Set(double deg,char s);
    bool SetFormat(char f);
    bool Convert(char sc);
    void Increment(int deg, char sc);


private:
    // these are attributes
    double degree;
    char scale;
    char format;
};