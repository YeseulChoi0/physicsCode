struct vector{
  double x,y;
};

struct kart{
  struct vector position;
  struct vector velocity;
  double acceleration;
};

struct kart initialize();
struct kart set_position(struct kart cart, double x, double y);
struct kart set_y_acceleration(struct kart cart, double y); //should be -1, 1 rad 2/ 2 or -rad 2/2
struct kart set_x_velocity(struct kart cart, double x); //should be rad 2/2 or -rad 2/2 (OR WHATEVER THE STANDARD BECOMES), hopefully 45 degree angle can be useful
struct kart move(struct kart currentKart, int xdir, int ydir, double timePassed);
struct kart update_position(struct kart currentKart, double timePassed);
