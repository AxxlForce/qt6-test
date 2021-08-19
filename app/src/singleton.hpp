#pragma once

#include "../../lib/thing.hpp"

#include <qqml.h>

#include <QObject>

class Singleton : public QObject
{
  Q_OBJECT
  QML_SINGLETON
  QML_ELEMENT
  Q_PROPERTY(Thing* thing READ getThing CONSTANT)

  static inline Thing* getThing()
  {
    static Thing thing;
    return &thing;
  }
};
