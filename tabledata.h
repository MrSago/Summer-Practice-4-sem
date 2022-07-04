#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractItemModel>
#include <QCompleter>

#include "prefixsearcher.h"

class TableData {
 public:
  TableData(const QVector<QString>& column_headers);
  ~TableData();
  QAbstractItemModel* getModel() { return model_; }
  void setSearchCriterionColumns(const QVector<int>& criterions);
  void addRow(QVector<QString>& columns);
  bool removeRow(int row);
  QVector<QString> getRowData(int row);
  void editRow(QVector<QString>& columns, int row);
  void resetModel();

 private:
  QAbstractItemModel* model_;
  QAbstractItemModel* const sourceModel_;
  QMap<int, PrefixSearcher*> criterionSearch_;
};

#endif  // TABLEMODEL_H