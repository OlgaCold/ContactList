#ifndef CONTACTS_H
#define CONTACTS_H

#include <QAbstractListModel>

class ContactModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ContactRole {
        NameRole = Qt::DisplayRole,
        NumberRole,
        ImageRole//
    };
    Q_ENUM(ContactRole)

    ContactModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const QString &fullName, const QString &number, const QString &image);
    Q_INVOKABLE void set(int row, const QString &fullName, const QString &number, const QString &image);
    Q_INVOKABLE void remove(int row);
    Q_INVOKABLE void call(int row);

private:
    struct Contact {
        QString name;
        QString number;
        QString image;
    };

    QList<Contact> m_contacts;
};

#endif // CONTACTS_H
