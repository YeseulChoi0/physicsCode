struct vector{
  double x,y;
};

struct kart{
  struct vector position;
  struct vector velocity;
  struct vector acceleration;
};

struct kart initialize();
struct kart set_position(struct kart cart, double x, double y);
struct kart set_acceleration(struct kart cart, double x, double y);
struct kart move(struct kart currentKart, int xdir, int ydir, double timePassed);
struct kart update_position(struct kart currentKart, double timePassed);
struct kart update_velocity(struct kart currentKart, double timePassed);
struct kart update_acceleration(struct kart currentKart, int xdir, int ydir);//negative number for down, left, position for up, right, 0 for neither
int add_acceleration(double currentA, double addition, int dir);
struct vector vector_addition(struct vector A, struct vector B);
struct vector scalar_mult(struct vector A, double multiplier);
