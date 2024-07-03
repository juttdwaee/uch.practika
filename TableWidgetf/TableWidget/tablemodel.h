#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;
#include <vector>

class TableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr);
    bool loadFromFile(const QString &fileName);
    bool saveToFile(const QString &fileName);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QXlsx::Document xlsx;
    std::vector<std::vector<QVariant>> m_data;
};

#endif // TABLEMODEL_H
