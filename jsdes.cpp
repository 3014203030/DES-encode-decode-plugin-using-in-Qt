#include "jsdes.h"
#include <QDebug>
JSDES::JSDES()
{
    this->readJs();
}
void JSDES::readJs()
{
    QString result = "";
    QFile scriptFile(":/des.js");
    if (!scriptFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error with opening js file..";
        result.clear();
        return;
    }
    QTextStream out(&scriptFile);
    QString contents = out.readAll();
    scriptFile.close();
    this->js = this->engine.evaluate(contents);        //个人理解：加载js文本到操作引擎
}
QString JSDES::DES_encode(QString data, QString key){
    QScriptValue func;
    QScriptValueList args;      //调用js方法时传入的参数
    args << QScriptValue(data)<<QScriptValue(key);
    func = engine.globalObject().property("DESencrypt");
    QString result = func.call(QScriptValue(), args).toString();
    return result;
}
QString JSDES::DES_decode(QString data, QString key){
    QScriptValue func;
    QScriptValueList args;      //调用js方法时传入的参数
    args << QScriptValue(data)<<QScriptValue(key);
    func = engine.globalObject().property("DESdecrypt");
    QString result = func.call(QScriptValue(), args).toString();
    return result;
}
