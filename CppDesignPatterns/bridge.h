#define interface struct

interface DrawAPI {
  virtual void drawCircle(int, int, int) = 0;
};

struct RedCircle : public DrawAPI {
  void drawCircle(int, int, int);
};

struct GreenCircle : public DrawAPI {
  void drawCircle(int, int, int);
};

class Shape 
{
  protected:
    DrawAPI *drawAPI;
    Shape(DrawAPI *);
  public:
    virtual void draw() = 0;	
};

class Circle : public Shape 
{
  private:
    int x, y, radius;
  public:
    Circle(int, int, int, DrawAPI *);
    void draw();
};