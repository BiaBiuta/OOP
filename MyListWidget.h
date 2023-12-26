#ifndef LAB_14_MYLISTMODEL_H
#define LAB_14_MYLISTMODEL_H
#include <QAbstractListModel>
#include <vector>
#include "Obiect.h"
#include"service.h"
#include <sstream>;
class MyListModel : public QAbstractListModel {
    vector<Obiect> subjects;
public:
    MyListModel(const std::vector<Obiect>& sbjs) : subjects(sbjs) {};
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return subjects.size();
    };
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
     
        if (role == Qt::DisplayRole) {
            //qDebug() << "get row:" << index.row();
            auto sp = subjects[index.row()].getTitlu();
            //qDebug() << sp;
            return QString::fromStdString(sp);
        }
        if (role == Qt::UserRole) {
            auto tp = subjects[index.row()].getType();
            return QString::fromStdString(tp);
        } 
        return QVariant{};
    };

};


#endif //LAB_14_MYLISTMODEL_H