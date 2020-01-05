struct vector{
  double x,y;
};

struct kart{
  struct vector position;
  struct vector velocity;
  struct vector acceleration;
};

struct kart initialize();
struct kart setPosition(struct kart cart, double x, double y);
struct kart setAcceleration(struct kart cart, double x, double y);
struct kart move(struct kart currentKart, int xdir, int ydir, double timePassed);
struct kart updatePosition(struct kart currentKart, double timePassed);
struct kart updateVelocity(struct kart currentKart, double timePassed);
struct kart updateAcceleration(struct kart currentKart, int xdir, int ydir);//negative number for down, left, position for up, right, 0 for neither
int addacceleration(double currentA, double addition, int dir);
struct vector vectorAddition(struct vector A, struct vector B);
