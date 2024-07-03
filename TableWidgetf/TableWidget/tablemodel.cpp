#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent) {
}

bool TableModel::loadFromFile(const QString &fileName) {
    QXlsx::Document xlsx(fileName);
    if (!xlsx.load()) {
        qWarning() << "Failed to load file" << fileName;
        return false;
    }

    m_data.clear();

    int maxRow = xlsx.dimension().lastRow();
    int maxCol = xlsx.dimension().lastColumn();

    for (int row = 1; row <= maxRow; ++row) {
        std::vector<QVariant> rowData;
        for (int col = 1; col <= maxCol; ++col) {
            QXlsx::Cell *cell = xlsx.cellAt(row, col);
            if (cell) {
                rowData.push_back(cell->value());
            } else {
                rowData.push_back(QVariant());
            }
        }
        m_data.push_back(rowData);
    }

    emit layoutChanged(); // Обновляем представление
    return true;
}

bool TableModel::saveToFile(const QString &fileName) {
    QXlsx::Document xlsx;
    for (int row = 0; row < m_data.size(); ++row) {
        for (int col = 0; col < m_data[row].size(); ++col) {
            xlsx.write(row + 1, col + 1, m_data[row][col]);
        }
    }
    return xlsx.saveAs(fileName);
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return static_cast<int>(m_data.size());
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return m_data.empty() ? 0 : static_cast<int>(m_data[0].size());
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return m_data[index.row()][index.column()];
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole) {
        m_data[index.row()][index.column()] = value;
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
        return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}
