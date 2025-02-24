#pragma once

#include <QRegularExpression>
#include <set>

#include "syntaxhighlighter.h"

namespace Ripes {

class RVSyntaxHighlighter : public SyntaxHighlighter {
public:
  RVSyntaxHighlighter(QTextDocument *parent, std::shared_ptr<Errors> errors,
                      const std::set<QString> &supportedOpcodes);
  void syntaxHighlightBlock(const QString &text) override;

private:
  struct HighlightingRule {
    QRegularExpression pattern;
    QTextCharFormat format;
  };
  QVector<HighlightingRule> m_highlightingRules;

  QTextCharFormat registerFormat;
  QTextCharFormat labelFormat;
  QTextCharFormat directiveFormat;
  QTextCharFormat instructionFormat;
  QTextCharFormat stringFormat;
  QTextCharFormat commentFormat;
  QTextCharFormat immediateFormat;

  // New color constant for lighter color
  static constexpr QColor LighterColor = QColor(0x33, 0x55, 0xbb); // Pdc60
};

} // namespace Ripes
