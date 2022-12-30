let list = [1, 2, 1, 1, 3, 4, 0]

const findNumberMajority = (list: Array<number>): number => {
    const numberCounts: {[num: number]: number} = {};

    // Create a {number: count} map
    list.map((val) => {
        if (val in numberCounts) {
            numberCounts[val]++
        } else {
            numberCounts[val] = 1
        }
    });

    // Find number with biggest count
    const sortedNumbers = Object.entries(numberCounts).reduce(
        (accumulator, current) => current[1] > accumulator[1] ? current : accumulator
    )

    // Return object key as number
    return Number(sortedNumbers[0])
}

console.log(findNumberMajority(list))

