#ifndef ACTION_H
#define ACTION_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class Action {
public:
    virtual ~Action() {}
    virtual void undo() = 0;
};

class AddItemAction : public Action {
public:
    AddItemAction(QGraphicsScene *scene, QGraphicsItem *item) : scene(scene), item(item) {}
    void undo() override {
        scene->removeItem(item);
        delete item;
    }

private:
    QGraphicsScene *scene;
    QGraphicsItem *item;
};

#endif // ACTION_H
