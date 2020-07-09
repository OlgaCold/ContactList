#include "ContactModel.h"

ContactModel::ContactModel(QObject *parent ) : QAbstractListModel(parent)
{
    m_contacts.append({ "Lily", "+38020678472", "qrc:///lily.jpg"});
    m_contacts.append({ "Geralt", "+38020655572", "qrc:///geralt.png"});
    m_contacts.append({ "Connor", "0351 7826892", "qrc:///connor.jpg" });
    m_contacts.append({ "Cara",  "+380204563672", "qrc:///default.png"});
    m_contacts.append({ "Markus", "+3802065782", "qrc:///default.png" });
    m_contacts.append({ "Hank Anderson", "+38026795572", "qrc:///hank.jpg"});
    m_contacts.append({ "Zlatko", "+3806955572", "qrc:///default.png" });
    m_contacts.append({ "Alice", "+38020690072", "qrc:///default.png" });
    m_contacts.append({ "Norma Rodriguez", "0241 5826596", "qrc:///default.png" });
    m_contacts.append({ "Shelia Ramirez", "0346 4844556", "qrc:///default.png" });
    m_contacts.append({ "Stephanie Moss", "0363 0510490", "qrc:///default.png" });
}

int ContactModel::rowCount(const QModelIndex &) const
{
    return m_contacts.count();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < rowCount())
        switch (role) {
        case NameRole: return m_contacts.at(index.row()).name;
        case NumberRole: return m_contacts.at(index.row()).number;
        case ImageRole: return m_contacts.at(index.row()).image;
        default: return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> ContactModel::roleNames() const
{
    static const QHash<int, QByteArray> roles {
        { NameRole, "name" },
        { NumberRole, "number" },
        { ImageRole, "image" }
    };
    return roles;
}

QVariantMap ContactModel::get(int row) const
{
    const Contact contact = m_contacts.value(row);
    return { {"name", contact.name},  {"number", contact.number}, {"image", contact.image} };
}

void ContactModel::append(const QString &name, const QString &number, const QString &image)
{
    int row = 0;
    while (row < m_contacts.count() && name > m_contacts.at(row).name)
        ++row;
    beginInsertRows(QModelIndex(), row, row);
    m_contacts.insert(row, {name, number, image});
    endInsertRows();
}

void ContactModel::set(int row, const QString &name, const QString &number, const QString &image)
{
    if (row < 0 || row >= m_contacts.count())
        return;

    m_contacts.replace(row, { name, number, image });
    dataChanged(index(row, 0), index(row, 0), { NameRole, NumberRole, ImageRole });
}

void ContactModel::remove(int row)
{
    if (row < 0 || row >= m_contacts.count())
        return;

    beginRemoveRows(QModelIndex(), row, row);
    m_contacts.removeAt(row);
    endRemoveRows();
}

void ContactModel::call(int row)
{
    //
}
