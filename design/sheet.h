#pragma once

#include "cell.h"
#include "common.h"

#include <functional>
#include <vector>

using Table = std::vector<std::vector<std::unique_ptr<Cell>>>;

class Sheet : public SheetInterface {
public:
    ~Sheet();

    void SetCell(Position pos, std::string text) override;
    
    CellInterface* GetCell(Position pos) override;
    const CellInterface* GetCell(Position pos) const override;
    Cell* Get_Cell(Position pos);
    const Cell* Get_Cell(Position pos) const;

    void ClearCell(Position pos) override;

    Size GetPrintableSize() const override;

    void PrintValues(std::ostream& output) const override;
    void PrintTexts(std::ostream& output) const override;

private:
	Table cells_;
};