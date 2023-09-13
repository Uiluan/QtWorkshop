#ifndef ALPHABETCIPHER_H
#define ALPHABETCIPHER_H

#include "MainWindow/MainWindowInterface.h"
#include <QMap>

class AlphabetCipher : public QObject
{
    Q_OBJECT

public:
    AlphabetCipher(MainWindowInterface& window, QObject *parent = nullptr);
    void Run();

private slots:
    void OnEncryptButtonClicked(const QString keyword, const QString message);
    void OnDecryptButtonClicked(const QString keyword, const QString message);

private:
    QMap<QChar, QMap<QChar, QChar>> &TransposeEncryptionMap();
    void BuildResultMessage(QString (AlphabetCipher::*charMapFunc)(QChar keyChar, QChar messageChar));
    QString GetEncryptionValue(QChar keyChar, QChar messageChar);
    QString GetDecryptionValue(QChar keyChar, QChar messageChar);

    MainWindowInterface *Window;
    QMap<QChar, QMap<QChar, QChar>> EncryptionMap;
    QMap<QChar, QMap<QChar, QChar>> DecryptionMap;
    QString Keyword;
    QString Message;
};

#endif // ALPHABETCIPHER_H
