/*********************************
 * gy_autotest.h
 *
 * By Gigi Young
 ********************************/

#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QPoint>
#include <QList>
#include <QGraphicsView>

class MainPlayer;
class ObjectHandler;
class SceneManager;

class AutoTest: public QObject {
    Q_OBJECT

public:
    AutoTest(QGraphicsScene *scene, SceneManager *sm=0, 
             QGraphicsItem *object=0) ; 
    bool change_scene(QGraphicsScene *scene);
    void create_stress_level();
    void restart_scene();
    void clear_scene();
    void add_point(QPoint point);

public slots:
    void simulate_keypress();

private:
    int list_pos;
    QPoint dest;
    QList<QPoint> points;

    MainPlayer *player; 
    QGraphicsItem *object;
    QTimer *timer;
    QGraphicsScene *scene;
    ObjectHandler *obj_handler;
    SceneManager *scene_manager;

};


#endif /* AUTOTEST_H */
