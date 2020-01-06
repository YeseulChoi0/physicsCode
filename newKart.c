#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "kart.h"

const double CONSTANT_ACCEL = 10;
const double MAX_ACCEL = 100;


struct kart initialize(){
  struct kart A;
  A.position.x = 0;
  A.position.y = 0;
  A.velocity.x = 0;
  A.velocity.y = 0;
  A.acceleration = 0;
  return A;
}

struct kart set_position(struct kart cart, double x, double y){
  cart.position.x = x;
  cart.position.y = y;
  return cart;
}

struct kart set_y_acceleration(struct kart cart, double y);{
  cart.acceleration = y;
  return cart;
}

struct kart set_x_velocity(struct kart cart, double x){
  cart.velocity.x = x;
  return cart;
}

struct kart move(struct kart currentKart, int x_vel, int y_acc, double timePassed){
  currentKart = set_x_velocity(currentKart, x_vel);
  currentKart = set_y_acceleration(currentKart, y_acc);
  currentKart = update_position(currentKart, timePassed);
  currentKart = update_velocity(currentKart, timePassed);
  return currentKart;
}

struct kart update_position(struct kart currentKart, double timePassed){
  currentKart.position.x += currentKart.velocity.x * timePassed;
  currentKart.position.y += (currentKart.velocity.y * timePassed) + (.5 * currentKart.acceleration *  pow(timePassed, 2));
  return currentKart;
}

struct kart update_velocity(struct kart currentKart, double timePassed){
  currentKart.velocity.y += currentKart.acceleration * timePassed;
  return currentKart;
}
