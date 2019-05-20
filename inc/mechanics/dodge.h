#pragma once

#include "misc/json.h"

#include "simulation/car.h"
#include "simulation/input.h"

#include "mechanics/aerial_turn.h"

#include "linear_algebra/math.h"

#include <optional>

class Dodge {

 public:
  Car & car;

  std::optional < vec3 > target;
  std::optional < vec2 > direction;
  std::optional < mat3 > preorientation;
  std::optional < float > duration;
  std::optional < float > delay;

  bool finished;
  Input controls;

  float timer;

  Dodge(Car & c);

  void step(float dt);

  Car simulate();

  nlohmann::json to_json();

  static const float timeout;
  static const float input_threshold;

  static const float z_damping;
  static const float z_damping_start;
  static const float z_damping_end;

  static const float torque_time;
  static const float side_torque;
  static const float forward_torque;

 private:

  AerialTurn turn;

};
