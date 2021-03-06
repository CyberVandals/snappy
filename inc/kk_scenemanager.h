#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>

#include "gy_object.h"

#include "hh_main_player.h"


#include "inc/gy_autotest.h"

class GameLevel;

class GameScene;

class ObjectHandler;

class LevelBuilder;

class SceneManager: public QGraphicsView
{
public:

    SceneManager(QGraphicsScene *scene);
    SceneManager(QGraphicsScene *scene, int demo, ObjectHandler *object_handler);
    void init(QGraphicsScene *scene, int demo);
    void play_game();
    void restart_game();
    void generate_level(const QString& filename);
    void next_level();
    MainPlayer* get_player();
private:
    void set_levels();
    ObjectHandler *object_handler = NULL;
    LevelBuilder *level_builder;
    MainPlayer *player;
    GameScene *main_scene;
    QGraphicsScene *scene;
    QList<QString> *levels = new QList<QString>();
};

#endif // SCENEMANAGER_H
