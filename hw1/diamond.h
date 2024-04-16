//--------------- Diamond.H ---------------

class Diamond
{
public:
   // constructor with parameters. default border = '#', default fill = '*'.
   Diamond(int x, char y='#', char z='*');

   // accessors
   int GetSize() const;
   int Perimeter() const;
   double Area() const;
   void Draw() const;
   void Summary() const;

   // mutator
   void Shrink();       // makes diamond's sides shrink by 1
   void Grow();	      // makes diamond's sides grow by 1
   void SetBorder(char y);
   void SetFill(char z);

private:
   // these are attributes
   int size;		
   char border;	
   char fill;	
};